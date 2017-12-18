/* https://codefights.com/arcade/code-arcade/intro-gates/mZAucMXhNMmT7JWta */

int phoneCall(int min1, int min2_10, int min11, int s) {
    int t = 0;
    int next_spend = min1;

    while(s >= next_spend) {
        s -= next_spend;
        t += 1;

        switch(t+1) {
            case 1:
                next_spend = min1;
                break;
            case 2 ... 10:
                next_spend = min2_10;
                break;
            default:
                next_spend = min11;
                break;
        }
    }

    return t;
}
