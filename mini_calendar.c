#include <stdio.h>
#include <stdbool.h>

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void add_days_to_date(int* dd, int* mm, int* yy, int days_left_to_add) {
  int days_left_in_month = 0;

  while(days_left_to_add > 0) {
    days_left_in_month = days_in_month[*mm - 1] - *dd;

    if (*mm == 2 && is_leap_year(*yy)) {
      days_left_in_month++;
    }

    if (days_left_to_add > days_left_in_month) {
      days_left_to_add -= days_left_in_month + 1;
      *dd = 1;
      if (*mm == 12) {
        *mm = 1;
        *yy = *yy + 1;
      } else {
        *mm = *mm + 1;
      }
    } else {
      *dd = *dd + days_left_to_add;
      days_left_to_add = 0;
    }
  }

}

int main() {

  int dd = 0;
  int mm = 0;
  int yyyy = 0;
  int days_left_to_add = 0;

  printf("Enter a date and the number of days to add (dd mm yyyy aa): ");
  scanf("%d %d %d %d", &dd, &mm, &yyyy, &days_left_to_add);

  add_days_to_date(&dd,&mm,&yyyy,days_left_to_add);
  printf("Date: %d %d %d", dd, mm, yyyy);

  return 0;
}