// 12S23019 - Clarasia L. Simanjuntak
// 12S23029 - Sintong Hutapea

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"


int main(int argc, char **argv) {
    struct student_t students[100];
    int student_count = 0;

    struct dorm_t *dormitories = NULL;
    int dormitory_count = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "---\n") == 0) {
            break;
        } else if (strcmp(input, "student-print-all\n") == 0) {
            print_student(students, student_count);
        } else if (strcmp(input, "dorm-print-all\n") == 0) {
            print_dorm(dormitories, dormitory_count);
        } else if (strcmp(input, "student-print-all-detail\n") == 0) {
            print_student_detail(students, student_count);
        } else if (strcmp(input, "dorm-print-all-detail\n") == 0) {
            print_dorm_detail(dormitories, dormitory_count);
        } else {
            char *token = strtok(input, "#");
            if (strcmp(token, "student-add") == 0) {
                char *id = strtok(NULL, "#");
                char *name = strtok(NULL, "#");
                char *year = strtok(NULL, "#");
                char *gender_str = strtok(NULL, "#");
                enum gender_t gender;
                if (strcmp(gender_str, "male\n") == 0) {
                    gender = GENDER_MALE;
                } else if (strcmp(gender_str, "female\n") == 0){
                    gender = GENDER_FEMALE;
                }
                students[student_count] = create_student(id, name, year, gender);
                student_count++;
            } else if(strcmp(token, "assign-student")==0){
                char *id = strtok(NULL, "#");
                char *dorm_name = strtok(NULL, "#");
                assign_student(students, dormitories, student_count, dormitory_count, id, dorm_name);
            } else if (strcmp(token, "dorm-add") == 0) {
                char *name = strtok(NULL, "#");
                char *capacity_str = strtok(NULL, "#");
                char *gender_str = strtok(NULL, "#");
                unsigned short capacity = atoi(capacity_str);
                enum gender_t gender;
                if (strcmp(gender_str, "male\n") == 0) {
                    gender = GENDER_MALE;
                } else {
                    gender = GENDER_FEMALE;
                }
                struct dorm_t new_dorm = create_dorm(name, capacity, gender);
                dormitory_count++;

                dormitories = realloc(dormitories, dormitory_count * sizeof(struct dorm_t));
                dormitories[dormitory_count - 1] = new_dorm;

            } else if(strcmp(token, "empty-dorm")==0){
                char *id = strtok(NULL, "#");
                char *dorm_name = strtok(NULL, "#");
                empty_dorm(dormitories, dormitory_count, dorm_name);
            }
         }
     } free(dormitories);

    return 0;
}