all : clean

clean :
	echo "Cleaning ..."
	find -name "*backups" -type d -exec rm -fr {} \; 2> /dev/null
	find -name "*FCStd1" -exec rm -fr {} \; 2> /dev/null
	find -name "*~" -exec rm -fr {} \; 2> /dev/null
	find -name "#*.dxf" -exec rm -fr {} \; 2> /dev/null

.SILENT : 
