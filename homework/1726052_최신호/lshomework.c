//출력 형식: file1, 접근권한, 생성시간, 파일크기, inode 번호
//getopt() 이용시 가점, ls는 readdir 사용, -l-i옵션은 stat 사용

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
	DIR *dirp;
	struct dirent *dentry;
	struct stat finfo;

	if((dirp = opendir(".")) == NULL)
		exit(1);

	while(dentry = readdir(dirp)) {		
		if(stat(dentry->d_name, &finfo) == -1) {	//예외처리+stat 불러오기
				printf("Couldn't stat %s \n", dentry->d_name);
				printf("%ld %d", dentry->d_ino, stat(dentry->d_name, &finfo));
				exit(1);
			} 
			printf("%s, %o, %u, %d, %d\n", dentry->d_name, finfo.st_mode,	finfo.st_ctim, finfo.st_size, dentry->d_ino);
		}
	closedir(dirp);
}
