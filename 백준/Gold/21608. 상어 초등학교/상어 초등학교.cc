#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int seats[21][21] = { 0 };
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<int> v[401];
int order[21][21];

int find_blank(int y, int x) {
    int sum = 0;
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (seats[ny][nx] == 0) sum++;
    }
    return sum;
}

int find_like(int student, int y, int x) {
    int sum = 0;
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        for(int j=1;j<=4;j++) if (seats[ny][nx] == v[student][j]) sum++;
    }
    return sum;
}

void solve() {
    for (int i = 0;i < n * n;i++) {
        int select_y = -1, select_x = -1, max_blank = -1, max_like = -1;
        for (int y = 0;y < n;y++) {
            for (int x = 0;x < n;x++) {
                if (seats[y][x] > 0) continue;
                else {
                    int blank_sum = find_blank(y, x);
                    int like_sum = find_like(i, y, x);
                    if (like_sum > max_like) {
                        select_y = y, select_x = x;
                        max_like = like_sum;
                        max_blank = blank_sum;
                    }
                    else if (like_sum == max_like) {
                        if (blank_sum > max_blank) {
                            select_y = y, select_x = x;
                            max_blank = blank_sum;
                        }
                        else if (blank_sum == max_blank) {
                            if (select_y > y) {
                                select_y = y, select_x = x;
                            }
                            else if(select_y==y && select_x>x) {
                                select_x = x, select_y = y;
                            }
                        }
                    }
                }
            }
        }
        seats[select_y][select_x] = v[i][0];
        order[select_y][select_x] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int myFriends = find_like(order[i][j], i, j);
            //cout << myFriends << ' ';
            if (myFriends == 1) {
                ans += 1;
            }
            else if (myFriends == 2) {
                ans += 10;
            }
            else if (myFriends == 3) {
                ans += 100;
            }
            else if (myFriends == 4) {
                ans += 1000;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int num;

    for (int i = 0;i < n*n;i++) {
        vector<int> temp;
        for (int i = 0;i < 5;i++) {
            cin >> num;
            temp.push_back(num);
        }
        v[i] = temp;
    }

    solve();

    //for (int i = 0;i < n;i++) {
    //    for (int j = 0;j < n;j++) {
    //        cout << seats[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    return 0;
}
