all :
	find -name "*backups" -type d -exec rm -fr {} \; 2> /dev/null
	find -name "*backups" -type d -exec rm -fr {} \; 2> /dev/null
	find -name "*~" -exec rm {} \; 2> /dev/null
	git add . && git commit -m \"$(date)\" && git push
 
