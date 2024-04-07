#include <stdio.h>

double sleeptime(int, int, int, int);
double sleep_grade(int, int, int, int);
double sleep_score(double, double);

int main() {
    int hour1, hour2, min1, min2;
    double sleeptime1, sleep_grade1, final_score;
    int before_sleep, m, n, drink_coffe, need_coffe;

    // ��ȡ˯��ʱ��
    printf("�������ϴ�ʱ�䣨��ʽ:07 12��: ");
    scanf("%d %d", &hour1, &min1);
    printf("����������ʱ�䣨��ʽ:07 12��: ");
    scanf("%d %d", &hour2, &min2);
    sleeptime1 = sleeptime(hour1, min1, hour2, min2);
    printf("˯ǰ��û�п��ֻ�/ˮcc98?\n[1]����bվ��������app [2]ˮ��cc98 [3]û��");
    scanf("%d", &before_sleep);
    if (before_sleep == 1) {
        sleeptime1 -= 60;
    } else if (before_sleep == 2) {
        sleeptime1 -= 30;
    } else {
        sleeptime1 -= 0;
    }

    // ��ȡ˯����������
    printf("�����ڵڼ����������ʱ����?(��Ȼ������0): ");
    scanf("%d", &n);
    printf("������������? (����0��1): ");
    scanf("%d", &m);
    printf("�����𴲵�ʱ���Ƿ���Ҫ�ȿ���? (��Ҫ����1, ����Ҫ����2): ");
    scanf("%d", &need_coffe);
    printf("������˿�����? (��������1, û������2): ");
    scanf("%d", &drink_coffe);
    sleep_grade1 = sleep_grade(m, n, drink_coffe, need_coffe);

    // �������յ÷�
    final_score = sleep_score(sleeptime1, sleep_grade1);

    // ������յ÷�
    printf("��������˯�ߵ÷���: %.2lf\n", final_score);

    return 0;
}

double sleeptime(int hour1, int min1, int hour2, int min2) {
    // ����˯��ʱ�䣬��СʱΪ��λ
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
    // ����˯������
    rest_level -= n * 20;
    rest_level -= m;
    if (need_coffe == 1 && drink_coffe == 0) { // ע�����������ӦΪdrink_coffe == 0����ʾû�кȿ���
        rest_level /= 1.3;
    }
    return rest_level;
}

double sleep_score(double sleep_time, double rest_level) {
    double score = 60.0;
    score = rest_level * (sleep_time / 60.0) / 100.0;
    return score;
}