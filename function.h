#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void match_func(int x); //매칭 시스템
void divisor_func(int x); // 약수 구하기
void GCD_func(int x, int y); // 최대 공약수 구하기
void print_data(char a); // 문자 출력
void get_nums(int* lotto_nums);//로또 번호 추첨(랜덤 번호 추첨, 중복된 번호 방지) //포인터 사용
void input_nums(int* lotto_nums); //직접 번호 입력(중복되면 이벤트 발생&다시 입력)
void print_nums(int* lotto_nums);  //번호 출력 // 포인터 변수 이용
char getGrade(int score);   //점수 입력 및 학점 부여 프로그램
void strExc_p(char* pa, char* pb); //문자열 복사
void getAcend(int* num, int size); //오름차순 버블 정렬
void getDcend(int* num, int count);//내림차순 버블 정렬
void selectionSort(int* num, int count); // 오름차순 선택 정렬
#endif