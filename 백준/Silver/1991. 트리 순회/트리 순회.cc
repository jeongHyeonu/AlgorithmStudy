#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int nodes[50][2];

void preorder(int n) {
    if (n == '.') return;
    cout <<  str[n];
    preorder(nodes[n][0]);
    preorder(nodes[n][1]);
}

void inorder(int n) {
    if (n == '.') return;
    inorder(nodes[n][0]);
    cout << str[n];
    inorder(nodes[n][1]);
}

void postorder(int n) {
    if (n == '.') return;
    postorder(nodes[n][0]);
    postorder(nodes[n][1]);
    cout << str[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char data, left, right;
    int N;
    
    cin >> N;
    for (int i = 0;i < N;i++) {
        cin >> data >> left >> right;
        int idx = data - 'A';

        if (left == '.') nodes[idx][0] = '.';
        else nodes[idx][0] = left - 'A';

        if (right == '.') nodes[idx][1] = '.';
        else nodes[idx][1] = right - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}