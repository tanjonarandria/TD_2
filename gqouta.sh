#!/bin/bash
#entrer en parametre partition: /home  ou /data
activation()
{
	sudo sed -i '|$1|d' /etc/fstab
	echo "/dev/sda $1 ext4 defaults,usrquota,grpquota 0 0" | sudo tee -a /etc/fstab	
	sudo mount -o remount $1
	sudo systemctl daemon-reload 
	sudo quotacheck -cum $1
	sudo quotacheck -gum $1
	sudo quotaon $1
}
# 2 parametre 1 option setquota ,  nom list_user ou group
edition_Softh() 
{
    	 for user in $(awk -F: '$3 >= 1000 && $3<=65000 { print $1 }' /etc/$(2)); do
	     
	     sudo setquota -$1 "$user" 52000000 70000000 0 0 /home
         done
}

# edition_inode  u (ou g) passwd(group)
edition_inod() 
{
	sudo quotacheck -cM /data
    
    	 for user in $(awk -F: '$3 >= 1000 && $3<=65000 { print $1 }' /etc/$(2)); do	     
	     	sudo setquota -$1 "$user" 0 0 500 600 /data
         done
}


verifi_Usofth() #recuperer nom user depasse limite  parametre option u ou g
{
	sudo requota -a -$1 /home |awk  '{ if ( $4 -gt 52000000 )
	                                   {
	                                     if ( $5 -gt 70000000 )
									     {
									       print  $1 >>"hard"
									     } 
									     else
									     {
									       print $1>>"soft"
									     }
								       }
									}	'		 	 
									
                                
}

verifi_inode()
{
	sudo requota -a -$1 /data |awk  '{ if ( $7 -gt 500 )
	                                   {
	                                      if ( $8 -gt 600 )
									      {
									        print  $1 >>"hardinode"
									      }
									      else
									      {
									        print $1>>"softinode"
									      }
								        }	
							         }'		 	 
									

}
#parametre 1:user/group 2:u ou g
rapport()
{
	touch hard soft  
   verifi_Usofth $(2)
   verifi_inode $(2)
   if [ -s hard ];then 
       echo "$(1) qui a depasse hardlimimte : "
	   awk '{
              print $1
			}' hard
   fi
   
   if [ -s soft ];then
        echo "$(1) qui a depasse softlimite : "
		awk '{
			   print $1
		     }' soft 
   fi
   if [-s softinode];then
   echo "$(1) qui a depasse softinode : "
		awk '{
			   print $1
		     }' softinode 
	fi
	if[ -s hardinode];then 
	echo "$(1) qui a depasse hardlimite : "
		awk '{
			   print $1
		     }' hardinode		 
}

umessage() 
{ 
   if [ -s hard ];then 
	   awk '{
              system("touch" /home/$1/message)  
			  print "hardquota depasse\n">> "/home/$1/message)
			 }' hard 
	
   if [ -s soft];then 
	   awk '{
              system("touch" /home/$1/message)  
			  print "softquota depasse\n">> "/home/$1/message)
			 }'soft

   if [ -s softinode];then 
	   awk '{
              system("touch" /home/$1/message)  
			  print "softinode depasse\n">> "/home/$1/message)
			 }'softinode
   


   if [ -s hardtinode ];then 
	   awk '{
              system("touch /home/$1/message)  
			  print "hardinode depasse\n" >> "/home/$1/message"
			 }	' hardinode	 
}

gmessage()
{
	if [ -s softinode ];then 
	   awk '{
		      grep $1 /etc/group | cut -d : -f4 | tr ',' '\n' > "list_users"  
              awk ' {
                      system("touch" /home/$1/message)  
			          print "softinode groupe depasse\n">> "/home/$1/message"
			        } ' list_users  
			 }	' softinode	 
    fi
    if [ -s hardtinode ];then 
	   awk '{
		      grep $1 /etc/group | cut -d : -f4 | tr ',' '\n' > "list_users"  
              awk ' {
                      system("touch" /home/$1/message)  
			          print "hardinode groupe depasse\n">> "/home/$1/message"
			        } ' list_users  
			 }	' hardinode	 
    fi 
	if [ -s softquota ];then 
	   awk '{
		      grep $1 /etc/group | cut -d : -f4 | tr ',' '\n' > "list_users"  
              awk ' {
                      system("touch" /home/$1/message)  
			          print "softquota groupe depasse\n">> "/home/$1/message"
			        } ' list_users  
			 }	' softquota
	fi		 
	if [ -s hardquota];then 
	   awk '{
		      grep $1 /etc/group | cut -d : -f4 | tr ',' '\n' > "list_users"  
              awk ' {
                      system("touch" /home/$1/message)  
			          print "hardquota groupe depasse\n">> "/home/$1/message"
			        } ' list_users  
			 }	' hardquota	
	fi		  	 		 			 
}

warning() #creer script affiche message  
{
	cat message | sudo tee -a  /etc/system_warning.txt 
	echo " if [-f /home/message]; if [ -f /home/message ] ; then ; cat /etc/message fi " |tee -a /etc/profile.d/display_warning.sh
	sudo chmod +x /etc/profile.d/display_warning.sh

}


main()
{

	activation /home
	edition_Softh u passwd
	edition_Softh g group
	edition_inod  u passwd
	edition_inod  g group
    rapport utilisateur u >rapport_userquota
    rapport groupe g >rapport_groupquota
    umessage 
	gmessage

}

cron()
{
	if[ ! -f /etc/cron/weekly/gquota.sh ];then 
   cp gquota.sh /etc/cron/weekly/
   chmod +x /etc/cron/weekly/gquota.sh
	else
	   main
	fi   
}
 
cron
