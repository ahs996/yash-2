#ifndef JOBS_H
#define JOBS_H

#include "parser.h"
#define JOB_RUNNING 0
#define JOB_STOPPED 1
#define JOB_DONE 2

struct Job {
  int pgid;
  int status;
  char* command;
};

struct JobsList {
  struct Job** jobs;
  int maxJobs;
  int numJobs;
  int highestJob;
  int lastJob;
};

struct JobsList* jobs;
int gpidRunning;
bool jobDone;

void fg_job();
void bg_job();
void init_jobs(int maxJobs);
int add_job(int pgid, char* jobString);
void remove_job(int pid);
void update_jobs();
void print_jobs();
void set_job_status(int jobNumber, int status);
void free_jobs();
#endif

