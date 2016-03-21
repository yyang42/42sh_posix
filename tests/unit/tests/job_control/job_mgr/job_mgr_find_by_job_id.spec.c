#include <project.h>

#include "shenv/shenv.h"
#include "job_control/job_mgr.h"

static void test_num1(t_test *test)
{
    t_job       *job21;
    t_job       *job42;
    t_job       *job84;
    t_lst       *jobs = shenv_singleton()->jobs;
    twl_lst_clear(jobs, job_del_void);
    job21 = job_new(1, "job 21", twl_lst_new());
    job21->job_id = 21;
    job42 = job_new(2, "job 42", twl_lst_new());
    job42->job_id = 42;
    job84 = job_new(3, "job 84", twl_lst_new());
    job84->job_id = 84;
    twl_lst_push_back(jobs, job21);
    twl_lst_push_back(jobs, job42);
    twl_lst_push_back(jobs, job84);
    mt_assert(job_mgr_find_by_job_id(jobs, "%21")->job_id == 21);
    mt_assert(job_mgr_find_by_job_id(jobs, "%42")->job_id == 42);
    mt_assert(job_mgr_find_by_job_id(jobs, "%84")->job_id == 84);
    mt_assert(job_mgr_find_by_job_id(jobs, "%100") == NULL);
    mt_assert(job_mgr_find_by_job_id(jobs, "%+")->job_id == 84);
    mt_assert(job_mgr_find_by_job_id(jobs, "%-")->job_id == 42);
    mt_assert(job_mgr_find_by_job_id(jobs, "0") == NULL);
    mt_assert(job_mgr_find_by_job_id(jobs, "x") == NULL);
    twl_lst_clear(jobs, job_del_void);
}


void            suite_job_mgr_find_by_job_id(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num1);
}
