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
    printf("˯ǰ��û�п��ֻ�/ˮcc98?\n[1]����bվ��������app   [2]ˮ��cc98    [3]û��   ");
    scanf("%d", &before_sleep);
    if (before_sleep == 1) {
        sleeptime1 -= 60;
    } else if (before_sleep == 2) {
        sleeptime1 -= 30;
    } else {
        sleeptime1-= 0;
    }

    // ��ȡ˯����������
    printf("�����ڵڼ����������ʱ����?(��Ȼ������0): ");
    scanf("%d", &n);
    printf("������������? (��������1, û����������0): ");
    scanf("%d", &m);
    printf("�����𴲵�ʱ���Ƿ���Ҫ�ȿ���? (��Ҫ����1, ����Ҫ����2): ");
    scanf("%d", &need_coffe);
    printf("������˿�����? (��������1, û������2): ");
    scanf("%d", &drink_coffe);
    sleep_grade1 = sleep_grade(m, n, drink_coffe, need_coffe);

    // �������յ÷�
    final_score = sleep_score(sleeptime1, sleep_grade1);

    // ������յ÷�
    printf("�÷���: %lf\n", final_score);

    //�����ϰʱ�ĸ������ݣ���ϰʱ�������ֻ����Σ�д�˶�����Ŀ�����޶������Ƿ�Ԥϰ��Ԥϰ�������λ����ڿ��鱾���Ƿ��пκ���ҵ��
    int study_hour, study_app, study_write, study_correct, study_pre, study_listen, study_homework, study_homework_score;
    printf("��������ϰʱ������λ��Сʱ��: ");
    scanf("%d", &study_hour);
    printf("�����ڿ��ֻ�����? (�������): ");
    scanf("%d", &study_app);
    printf("����д�˶�����Ŀ? (������Ŀ��): ");
    scanf("%d", &study_write);
    printf("�������޶���? (���붩����Ŀ��): ");
    scanf("%d", &study_correct);
    printf("�����Ƿ�Ԥϰ? (������1, ������2): ");
    scanf("%d", &study_pre);
    printf("����Ԥϰ�������λ����ڿ��鱾? (��������1, ���鱾����2): ");
    scanf("%d", &study_listen);
    printf("�������޿κ���ҵ? (������1, ������2): ");
    scanf("%d", &study_homework);
    if (study_homework == 1) {
        printf("��������ҵ����: ");
        scanf("%d", &study_homework_score);
    }
    // ������ϰ�÷�
    double study_score = 0.0;
    study_score = (study_hour-4) * 10 - study_app * 5 + (study_write) * 15 + (study_correct) * 20 + (study_pre-1.5) * 5 + study_listen * 5;
    if (study_homework == 1) {
        study_score += study_homework_score * 20;
    }
    printf("������ϰ�÷���: %lf\n", study_score);
    //�ж��Լ��Ƿ��Ͽ�
    int is_study = 0;
    printf("���Ƿ��Ͽ�? (�Ͽ�����1, ���Ͽ�����2): ");
    scanf("%d", &is_study);
    double play_score = 0.0;
    if (is_study == 1) {
        // �����Ͽε÷�
            // �����Ͽε÷�
        /*��ȡ�Լ��Ͽ����ֻ��������Ƿ�Ǳʼǣ��Ƿ������������Ƿ��ڿ�����pre���Ƿ���Ҫ�ؿ����ƣ��Ƿ�������п������⡣�����Լ��Ͽε�Ч�ʣ������*/
    int play_phone, note_book, listen_lecture, pre_in_class, review_ziyun, understand_example;
        printf("���Ͽ����ֻ�����: ");
        scanf("%d", &play_phone);
        printf("���Ƿ�Ǳʼ�? (�Ǳʼ�����1, ���Ǳʼ�����2): ");
        scanf("%d", &note_book);
        printf("���Ƿ���������? (������������1, ��������������2): ");
        scanf("%d", &listen_lecture);
        printf("���Ƿ��ڿ�����pre? (��pre����1, û��pre����2): ");
        scanf("%d", &pre_in_class);
        printf("���Ƿ���Ҫ�ؿ�����? (��Ҫ�ؿ�����1, ����Ҫ�ؿ�����2): ");
        scanf("%d", &review_ziyun);
        printf("���Ƿ�������п�������? (������п�����������1, ��������п�����������2): ");
        scanf("%d", &understand_example);
                
        play_score = -1*play_phone * 10 + note_book * 10 + listen_lecture * 5 + pre_in_class * (-5) + review_ziyun * ( -2 ) + understand_example * 20;
        printf("�����Ͽ����ֻ��÷���: %lf\n", play_score);
    } else {
        printf("��û���ϿΣ��������Ͽε÷֡�\n");
    }
    /*�����Լ��˶��������Ӱ�죬��Ҫ����ÿ�춽���Լ���3-5km�����ߴ�����1h��������ϰ���͵��ǲ��������۵�״̬��������Լ����˶��÷�*/
    
    // ����������ж�Ӧ����run_km >= 3 && run_km <= 5 || play_ball >= 1 || exercise_state == 1 ���������������ͬʱ�������������Ҫ���۷�
    //����ܲ���10km������discount = 0.8������ܲ�����10km��discount = 1.0
    //����������������õĻ��������ʵ��ӷ֣�����if�жϣ�
    //����ܲ�3km���ֽ��д�������ô��Ҫ�۷ֽ϶�
    //����ܲ�3km���ֽ�����ϰ����ô��Ҫ�۷ֽ϶�
    int run_km, play_ball, exercise_state;
    printf("���������������˶��ٹ���? (��λ������): ");
    scanf("%d", &run_km);
    printf("�������Ƿ������? (����������1, ������������2): ");
    scanf("%d", &play_ball);
    printf("�������Ƿ���ϰ? (��ϰ����1, ����ϰ����2): ");
    scanf("%d", &exercise_state);
    double exercise_score = 0.0;
    if (run_km >= 3 && run_km <= 5) {
        if (play_ball == 1) {
            exercise_score = 100.0;
        } else if (exercise_state == 1) {
            exercise_score = 80.0;
        } else {
            exercise_score = 60.0;
        }
    } else if (run_km >= 10) {
        if (play_ball == 1) {
            exercise_score = 80.0;
        } else if (exercise_state == 1) {
            exercise_score = 60.0;
        } else {
            exercise_score = 40.0;
        }
    } else {
        if (play_ball == 1) {
            exercise_score = 60.0;
        } else if (exercise_state == 1) {
            exercise_score = 40.0;
        } else {
            exercise_score = 20.0;
        }
    }
    printf("�����˶��÷���: %lf\n", exercise_score);
    // �����ܷ֣�����study_score��play_score��exercise_score��Ȩ��
    //study_scoreȨ����ߣ�play_score��֮��exercise_score���
    double total_score = study_score * 0.5 + play_score* 0.2 + exercise_score * 0.3;
    printf("�����ܵ÷���: %lf\n", total_score);
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
