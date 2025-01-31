#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int bit = 0;
    int m;
    cin >> m;

    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "add") {
            cin >> x;
            bit |= (1 << x);
        }
        else if (op == "remove") {
            cin >> x;
            if (bit & (1 << x)) // x�� �ִ� ��쿡�� ����
                bit &= ~(1 << x);
        }
        else if (op == "check") {
            cin >> x;
            cout << ((bit & (1 << x)) ? 1 : 0) << "\n";
        }
        else if (op == "toggle") {
            cin >> x;
            bit ^= (1 << x); // x�� ������ ����, ������ �߰�
        }
        else if (op == "all") {
            bit = (1 << 21) - 1;
        }
        else if (op == "empty") {
            bit = 0;
        }
    }
}
