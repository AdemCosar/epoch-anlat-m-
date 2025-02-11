#include <stdio.h>
#include <time.h>

struct TaskTime {
    struct tm start_time;
    struct tm end_time;
};

union EpochTime {
    time_t epoch;
    struct tm timeStruct;
};

time_t convertToEpoch(struct tm timeStruct) {
    return mktime(&timeStruct);
}

int main() {
    struct TaskTime task;
    union EpochTime start, end;
    
    printf("Görev başlangıç zamanını giriniz:\n");
    printf("Yıl (YYYY): "); scanf("%d", &task.start_time.tm_year); task.start_time.tm_year -= 1900;
    printf("Ay (1-12): "); scanf("%d", &task.start_time.tm_mon); task.start_time.tm_mon -= 1;
    printf("Gün (1-31): "); scanf("%d", &task.start_time.tm_mday);
    printf("Saat (0-23): "); scanf("%d", &task.start_time.tm_hour);
    printf("Dakika (0-59): "); scanf("%d", &task.start_time.tm_min);
    printf("Saniye (0-59): "); scanf("%d", &task.start_time.tm_sec);

    printf("\nGörev bitiş zamanını giriniz:\n");
    printf("Yıl (YYYY): "); scanf("%d", &task.end_time.tm_year); task.end_time.tm_year -= 1900;
    printf("Ay (1-12): "); scanf("%d", &task.end_time.tm_mon); task.end_time.tm_mon -= 1;
    printf("Gün (1-31): "); scanf("%d", &task.end_time.tm_mday);
    printf("Saat (0-23): "); scanf("%d", &task.end_time.tm_hour);
    printf("Dakika (0-59): "); scanf("%d", &task.end_time.tm_min);
    printf("Saniye (0-59): "); scanf("%d", &task.end_time.tm_sec);

    start.epoch = convertToEpoch(task.start_time);
    end.epoch = convertToEpoch(task.end_time);

    double difference = difftime(end.epoch, start.epoch);

    printf("\nGörev başlangıç epoch zamanı: %ld saniye\n", start.epoch);
    printf("Görev bitiş epoch zamanı: %ld saniye\n", end.epoch);
    printf("Görev süresi: %.0f saniye (%.2f saat)\n", difference, difference / 3600);

    return 0;
}
