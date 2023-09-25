/*************************************************************************
	> File Name: 03.ls功能模拟.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 10:37:07 AM CST
 ************************************************************************/

#include "../common/head.h"

int l_flag = 0;
int a_flag = 0;
int dir_num = 0;

void do_ls(const char *name);
void do_stat(const char *name);
void showinfo(const char *name, struct stat* st);
void mode_2_str(mode_t mode, char *str);
char *uid_2_name(uid_t uid);
char *gid_2_name(gid_t gid);


int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': {
                a_flag = 1;
            } break;
            case 'l': {
                l_flag = 1;
            } break;
            default : {
                fprintf(stderr, "Usage : %s [-al] [args...]\n", argv[0]);
                exit(1);
            } break;
        }
    }
    
    argc -= (optind - 1);
    argv += (optind - 1);
    DBG("argc = %d, argv[1] = %s\n", argc, argv[1]);
    dir_num = argc;

    if (argc == 1) {
        do_ls(".");
    } else {
        for (int i = 1; i < argc; i++) {
            do_ls(argv[i]);
        }
    }
    return 0;
}

void do_ls(const char *name) {
    DBG("%s\n", name);
    DIR *dir = NULL;
    struct dirent* direntp;
    if ((dir = opendir(name)) == NULL) {
        DBG("Open Error\n"); 
        //目录打开失败
        if (access(name, R_OK) == 0) {
            if (l_flag == 1) {
                //是文件，输出
                do_stat(name);
            } else {
                //不是文件，就输出目录名
                printf("%s\n", name);
            }
        }

    } else {
        DBG("Open Success!\n");
        if (dir_num > 1) {
            printf("%s:\n", name);
        }
        while ((direntp = readdir(dir))) {
            if (a_flag == 0 && direntp->d_name[0] == '.') continue;
            if (l_flag == 1) {
                do_stat(direntp->d_name);
            }
        }
    } 
    return ;
}

void do_stat(const char *name) {
    DBG("%s\n", name);
    struct stat st;
    if (lstat(name, &st) < 0) {
        perror(name);
        exit(1);
    }
    DBG("uid = %d\n", st.st_uid);
    showinfo(name, &st);
    return ;
}

void mode_2_str(mode_t mode, char *str) {
    if (S_ISREG(mode)) str[0] = '-';
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
    if (S_ISSOCK(mode)) str[0] = 's';
    if (S_ISFIFO(mode)) str[0] = 'p';
    if (S_ISLNK(mode)) str[0] = 'l';
    
    //用户权限
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    //组权限
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';
    
    //其他用户权限
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';

    return ;
}

char *uid_2_name(uid_t uid) {
   struct passwd *pwd;
    static char tmpname[20] = {0};
    if ((pwd = getpwuid(uid)) == NULL) {
        sprintf(tmpname, "%d", uid);
        return tmpname;
    } else {
        return pwd->pw_name;
    }
}

char *gid_2_name(gid_t gid) {
    struct group *grp;
    static char tmpname[20] = {0};
    if ((grp = getgrgid(gid)) == NULL) {
        sprintf(tmpname, "%d", gid);
        return tmpname;
    } else {
        return grp->gr_name;
    }
}

void showinfo(const char *name, struct stat *st) {
    char modstr[15] = "----------";
    mode_2_str(st->st_mode, modstr);
    printf("%s", modstr);
    printf("%3ld", st->st_nlink);
    printf("%10s", uid_2_name(st->st_uid));
    printf("%10s", gid_2_name(st->st_gid));
    printf("\n");
    return ;
}
