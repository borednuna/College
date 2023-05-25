#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

//dibagian parent process hitung jumlah daemon process dari daemon-process.txt hasilbya dimasukin di total-daemon-process.txt
int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        exit(1);
    } else

    if (pid == 0) {
        // char *argv[] = {"pwd", NULL};
        // execv("/bin/pwd", argv);
        // system("ps -A | grep '[dD]aemon' > daemon-process.txt");
        // system("chmod 764 daemon-process.txt");
        // system("chmod u+rwx,g+rw,o+r daemon-process.txt");

        system("rm daemon-process.txt total-daemon-process.txt output");
    } else {
        // char *argv[] = {"mkdir", "output", NULL};
        // execv("/bin/mkdir", argv);

        // FILE *input;
        // char buffer[100];
        // int processes = 0;

        // input = fopen("daemon-process.txt", "r");

        // if (input == NULL) {
        //     exit(1);
        // }

        // while (fgets(buffer, sizeof(buffer), input)) {
        //     if (strlen(buffer) > 1) {
        //         processes++;
        //     }
        // }

        // fclose(input);

        // FILE *output;
        // output = fopen("total-daemon-process.txt", "w");
        // fprintf(output, "%d\n", processes);
        // system("sudo chown root total-daemon-process.txt");
    }
}