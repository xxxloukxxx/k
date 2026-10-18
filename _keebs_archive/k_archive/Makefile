
all: clean

clean:
	find -name "*backups" -type d -print0 | xargs -r0 -- rm -r
	find -name *.FCStd1 -print0 | xargs -r0 -- rm -r
	find -name *.~ -print0 | xargs -r0 -- rm -r
	find -name *.dxf~ -print0 | xargs -r0 -- rm -r
	find -name *backups -print0 | xargs -r0 -- rm -r

push: clean
	git add .
	/usr/bin/date > /tmp/commit_msg
	git commit -F /tmp/commit_msg --allow-empty
	git push

.SILENT:


