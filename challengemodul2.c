// pertanyaan yg di terminal
// 1. kalian disuru tampilin proses yg berjalan => ps aux
// 2. disuruh tampilin pstree terserah pidnya mau diambil yang mana, pokoknya jangan yg root => pstree <PID>
// 3. kill proses, sabeb yg mana asal bukan yg root, yg pid pstree tadi juga boleh dipake untuk kill ini => kill -9 <PID>

// lanjut ke bikin file c namanya modul2test.c => touch modul2test.c
// code . ngoding di vscode/sabeb dimana
// lanjut soal soal dibawah
//soal1
// file ini bisa jalanin prinsip fork untuk spawning process 
// di bagian child process menjalankan perintah pwd, di bagian parent process menjalankan mkdir dengan output dir namanya output

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0 ){
        exit(1);
    }
    else if(pid==0){
        char *argv[] = {"pwd", NULL};
        execv("/bin/pwd", argv);
    }
    else {
        char *argv[] = {"mkdir", "output", NULL};
        execv("/bin/mkdir", argv);
    }
}

//soal 2
//di baigian child process, ubah fungsi child process untuk mendapatkan jumlah proses daemon yang sedang berjalan
// lalu haisilnya disimpan di daemon-process.txt

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0 ){
        exit(1);
    }
    else if(pid==0){
        system("ps -e | grep '[dD]aemon' > output/daemon-process.txt");
        exit(1);

        // yg ini gaperlu, pake yg atas
        // FILE *fp = fopen("daemon_process.txt", "w");
        // if(fp == NULL){
        //     exit(1);
        // }
        // // fprint(fp, "%d", pid);
        // fclose(fp);
    }
    else {
        char *argv[] = {"mkdir", "output", NULL};
        execv("/bin/mkdir", argv);
    }
}

//soal 3
//dibagian parent process hitung jumlah daemon process dari daemon-process.txt hasilbya dimasukin di total-daemon-process.txt

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0 ){
        exit(1);
    }
    else if(pid==0){
        system("ps -e | grep '[dD]aemon' > output/daemon-process.txt");
        exit(1);

        // FILE *fp = fopen("daemon_process.txt", "w");
        // if(fp == NULL){
        //     exit(1);
        // }
        // // fprint(fp, "%d", pid);
        // fclose(fp);
    }
    else {
        FILE *fp = fopen("/home/sabrina/Documents/output/daemon-process.txt", "r");

        int pid;
        fscanf(fp, "%d", &pid);
        fclose(fp);

        FILE *fpp = fopen("total-daemon-process.txt", "w");
        fprintf(fpp, "%d", pid);
        fclose(fpp);

        exit(EXIT_SUCCESS);
    }
}

//soal 4
//ubah child process, untuk mengubah file permission dari file daemon-process.txt ke rwxrw-r--
//di parent process ubah file ownership dari file total-daemon-process.txt ke user root

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0 ){
        exit(1);
    }
    else if(pid==0){
        system("ps -e | grep '[dD]aemon' > output/daemon-process.txt");
        exit(1);

        // FILE *fp = fopen("daemon_process.txt", "w");
        // if(fp == NULL){
        //     exit(1);
        // }
        // // fprint(fp, "%d", pid);
        // fclose(fp);

        //system("chmod 764 daemon-process.txt"); //ini aku salaaa, gatau yg bener gimana
        chmod("daemon-process.txt", S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH); //kata masnya pake ini tp aku ls -l masi gaberubah
    }
    else {
        FILE *fp = fopen("/home/sabrina/Documents/output/daemon-process.txt", "r");

        int pid;
        fscanf(fp, "%d", &pid);
        fclose(fp);

        FILE *fpp = fopen("total-daemon-process.txt", "w");
        fprintf(fpp, "%d", pid);
        fclose(fpp);

        system("sudo chown root total-daemon-process.txt");

        exit(EXIT_SUCCESS);
    }
}

// soal 5
//pada child process hapus file daemon-process.txt, total-daemon-process.txt, dan hapus dir output
int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0 ){
        exit(1);
    }
    else if(pid==0){
        system("rm daemon-process.txt total-daemon-process.txt");
        system("rm -r output");

    }
}