#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

main()
{
    pid_t pid, ret;
    int status = 0;
    char in_buf[256];

    while (1)
    {
        printf("$");
        fgets(in_buf, 256, stdin);
        in_buf[strlen(in_buf) - 1] = '\0';
        
        if (pid = fork() > 0)
        {
            ret = waitpid(pid, &status, 0);
            printf("%s\n", WIFEXITED(status) ? "성공" : "실패");
        }
        else if (pid == 0)
        {
            execlp(in_buf, in_buf, NULL);
        }
        else
        {
            printf("fail to fork\n");
        }
    }
    return 0;
}