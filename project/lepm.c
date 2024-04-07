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
    printf("睡前有没有看手机/水cc98?\n[1]看了b站或者其他app   [2]水了cc98    [3]没看   ");
    scanf("%d", &before_sleep);
    if (before_sleep == 1) {
        sleeptime1 -= 60;
    } else if (before_sleep == 2) {
        sleeptime1 -= 30;
    } else {
        sleeptime1-= 0;
    }

    // 获取睡眠质量评分
    printf("今天在第几个闹钟响的时候起床?(自然醒输入0): ");
    scanf("%d", &n);
    printf("今天做梦了吗? (做梦输入1, 没有做梦输入0): ");
    scanf("%d", &m);
    printf("今天起床的时候是否需要喝咖啡? (需要输入1, 不需要输入2): ");
    scanf("%d", &need_coffe);
    printf("今天喝了咖啡吗? (喝了输入1, 没喝输入2): ");
    scanf("%d", &drink_coffe);
    sleep_grade1 = sleep_grade(m, n, drink_coffe, need_coffe);

    // 计算最终得分
    final_score = sleep_score(sleeptime1, sleep_grade1);

    // 输出最终得分
    printf("得分是: %lf\n", final_score);

    //获得自习时的各项数据：自习时长，看手机几次，写了多少题目，有无订正，是否预习，预习是在听课还是在看书本，是否有课后作业，
    int study_hour, study_app, study_write, study_correct, study_pre, study_listen, study_homework, study_homework_score;
    printf("请输入自习时长（单位：小时）: ");
    scanf("%d", &study_hour);
    printf("今天在看手机几次? (输入次数): ");
    scanf("%d", &study_app);
    printf("今天写了多少题目? (输入题目数): ");
    scanf("%d", &study_write);
    printf("今天有无订正? (输入订正题目数): ");
    scanf("%d", &study_correct);
    printf("今天是否预习? (是输入1, 否输入2): ");
    scanf("%d", &study_pre);
    printf("今天预习是在听课还是在看书本? (听课输入1, 看书本输入2): ");
    scanf("%d", &study_listen);
    printf("今天有无课后作业? (有输入1, 无输入2): ");
    scanf("%d", &study_homework);
    if (study_homework == 1) {
        printf("请输入作业分数: ");
        scanf("%d", &study_homework_score);
    }
    // 计算自习得分
    double study_score = 0.0;
    study_score = (study_hour-4) * 10 - study_app * 5 + (study_write) * 15 + (study_correct) * 20 + (study_pre-1.5) * 5 + study_listen * 5;
    if (study_homework == 1) {
        study_score += study_homework_score * 20;
    }
    printf("您的自习得分是: %lf\n", study_score);
    //判断自己是否上课
    int is_study = 0;
    printf("您是否上课? (上课输入1, 不上课输入2): ");
    scanf("%d", &is_study);
    double play_score = 0.0;
    if (is_study == 1) {
        // 计算上课得分
            // 计算上课得分
        /*获取自己上课玩手机次数，是否记笔记，是否认真听讲，是否在课上有pre，是否需要回看智云，是否理解所有课堂例题。计算自己上课的效率，并输出*/
    int play_phone, note_book, listen_lecture, pre_in_class, review_ziyun, understand_example;
        printf("您上课玩手机次数: ");
        scanf("%d", &play_phone);
        printf("您是否记笔记? (记笔记输入1, 不记笔记输入2): ");
        scanf("%d", &note_book);
        printf("您是否认真听讲? (认真听讲输入1, 不认真听讲输入2): ");
        scanf("%d", &listen_lecture);
        printf("您是否在课上有pre? (有pre输入1, 没有pre输入2): ");
        scanf("%d", &pre_in_class);
        printf("您是否需要回看智云? (需要回看输入1, 不需要回看输入2): ");
        scanf("%d", &review_ziyun);
        printf("您是否理解所有课堂例题? (理解所有课堂例题输入1, 不理解所有课堂例题输入2): ");
        scanf("%d", &understand_example);
                
        play_score = -1*play_phone * 10 + note_book * 10 + listen_lecture * 5 + pre_in_class * (-5) + review_ziyun * ( -2 ) + understand_example * 20;
        printf("您的上课玩手机得分是: %lf\n", play_score);
    } else {
        printf("您没有上课，不计算上课得分。\n");
    }
    /*计算自己运动对身体的影响，需要做到每天督促自己跑3-5km，或者打篮球1h，或者练习速耐但是不过度劳累的状态，并输出自己的运动得分*/
    
    // 这里的条件判断应该是run_km >= 3 && run_km <= 5 || play_ball >= 1 || exercise_state == 1 如果出现两个条件同时成立的情况，还要倒扣分
    //如果跑步到10km以上则discount = 0.8，如果跑步不到10km则discount = 1.0
    //打篮球如果心情愉悦的话，可以适当加分（进行if判断）
    //如果跑步3km，又进行打篮球，那么需要扣分较多
    //如果跑步3km，又进行练习，那么需要扣分较多
    int run_km, play_ball, exercise_state;
    printf("请输入您今天跑了多少公里? (单位：公里): ");
    scanf("%d", &run_km);
    printf("您今天是否打篮球? (打篮球输入1, 不打篮球输入2): ");
    scanf("%d", &play_ball);
    printf("您今天是否练习? (练习输入1, 不练习输入2): ");
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
    printf("您的运动得分是: %lf\n", exercise_score);
    // 计算总分，给出study_score，play_score，exercise_score的权重
    //study_score权重最高，play_score次之，exercise_score最低
    double total_score = study_score * 0.5 + play_score* 0.2 + exercise_score * 0.3;
    printf("您的总得分是: %lf\n", total_score);
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
