int main() {
    int N = 10;
    int T1 = 0, T2 = 1, T3;

    printf("%d %d ", T1, T2);

    for (int i = 3; i <= N; i++) {
        T3 = T1 + T2;
        printf("%d ", T3);
        T1 = T2;
        T2 = T3;
    }

    return 0;
}
