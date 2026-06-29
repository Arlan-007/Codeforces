int main() {
    array(string) parts = Stdio.stdin->gets() / " ";
    int n = (int)parts[0];
    int k = (int)parts[1];
    int n1 = (int)parts[2];

    int side = n / n1;
    if (n % n1 != 0) side++;
    int num = side * side;

    if (num > k)
        write("NO\n");
    else
        write("YES\n");

    return 0;
}