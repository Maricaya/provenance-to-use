#ifndef _CDE_H
#define _CDE_H

extern char Cde_verbose_mode;    // print cde activity to stdout (-v option)
extern char Cde_exec_mode;       // false if auditing, true if running captured app
extern char Cde_app_dir[];       // abs path to cde app dir (contains cde-root)
extern char Cde_follow_ssh_mode;

// to shut up gcc warnings without causing nasty #include conflicts
// TODO: do we still need this?
int shmget(key_t key, size_t size, int shmflg);
void *shmat(int shmid, const void *shmaddr, int shmflg);
int shmdt(const void *shmaddr);
int shmctl(int shmid, int cmd, struct shmid_ds *buf);

// like an assert except that it always fires
#define EXITIF(x) do { \
  if (x) { \
    fprintf(stderr, "Fatal error in %s [%s:%d]\n", __FUNCTION__, __FILE__, __LINE__); \
    exit(1); \
  } \
} while(0)

#endif // _CDE_H

