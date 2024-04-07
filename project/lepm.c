#include <stdio.h>

double sleeptime(int, int, int, int);
double sleep_grade(int, int, int, int);
double sleep_score(double, double);

int main() {
    int hour1, hour2, min1, min2;
    double sleeptime1, sleep_grade1, final_score;
    int before_sleep, m, n, drink_coffe, need_coffe;

    // 获取睡眠时间
    printf("请输入上床时间（格式:07 12）: ");
    scanf("%d %d", &hour1, &min1);
    printf("现在输入起床时间（格式:07 12）: ");
    scanf("%d %d", &hour2, &min2);
    sleeptime1 = sleeptime(hour1, min1, hour2, min2);
    printf("睡前有没有看手机/水cc98?\n[1]看了b站或者其他app [2]水了cc98 [3]没看");
    scanf("%d", &before_sleep);
    if (before_sleep == 1) {
        sleeptime1 -= 60;
    } else if (before_sleep == 2) {
        sleeptime1 -= 30;
    } else {
        sleeptime1 -= 0;
    }

    // 获取睡眠质量评分
    printf("今天在第几个闹钟响的时候起床?(自然醒输入0): ");
    scanf("%d", &n);
    printf("今天做梦了吗? (输入0或1): ");
    scanf("%d", &m);
    printf("今天起床的时候是否需要喝咖啡? (需要输入1, 不需要输入2): ");
    scanf("%d", &need_coffe);
    printf("今天喝了咖啡吗? (喝了输入1, 没喝输入2): ");
    scanf("%d", &drink_coffe);
    sleep_grade1 = sleep_grade(m, n, drink_coffe, need_coffe);

    // 计算最终得分
    final_score = sleep_score(sleeptime1, sleep_grade1);

    // 输出最终得分
    printf("您的最终睡眠得分是: %.2lf\n", final_score);

    return 0;
}

double sleeptime(int hour1, int min1, int hour2, int min2) {
    // 计算睡眠时间，以小时为单位
    double sleep_hours;
    if (hour2 < hour1) {
        sleep_hours = (24 - hour1) + (hour2 * 1.0 / 60) + (min2 - min1) / 60.0;
    } else {
        sleep_hours = (hour2 - hour1) * 1.0 / 60 + (min2 - min1) / 60.0;
    }
    return sleep_hours;
}

double sleep_grade(int m, int n, int drink_coffe, int need_coffe) {
    double rest_level = 100.0;
    // 计算睡眠质量
    rest_level -= n * 20;
    rest_level -= m;
    if (need_coffe == 1 && drink_coffe == 0) { // 注意这里的条件应为drink_coffe == 0，表示没有喝咖啡
        rest_level /= 1.3;
    }
    return rest_level;
}

double sleep_score(double sleep_time, double rest_level) {
    double score = 60.0;
    score = rest_level * (sleep_time / 60.0) / 100.0;
    return score;
}