#ifndef STUDENT_H
#define STUDENT_H

#include "dorm.h"

enum gender_t {
    GENDER_MALE,
    GENDER_FEMALE
};

enum status_t {
    UNASSIGNED,
    ASSIGNED
};

struct student_t {
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
    enum status_t status; // Tambahkan status_t di sini
};

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);
void print_student_detail(struct student_t *students, int student_count);

#endif
