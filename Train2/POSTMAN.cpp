
    #include <iostream>
    #include <bits/stdc++.h>
    #include <math.h>
    #include <string>

using namespace std;

typedef struct customer
{
    int x;
    int pro;
} customer;

customer create_customer(int x, int pro)
{
    customer c;
    c.x = x;
    c.pro = pro;
    return c;
}

bool descend(customer a, customer b)
{
    return (a.x > b.x);
}
bool increase(customer a, customer b)
{
    return (a.x < b.x);
}

void send_product(vector<customer> &list, int capacity)
{
    int sub;

    if(list.back().pro == 0){
        list.pop_back();
        return;
    }
        

    for (int i = list.size() - 1; i >= 0; i--)
    {
        sub = capacity - list[i].pro;

        if (sub >= 0)
        {
            list.pop_back();
            capacity = sub;
        }
        else
        {
            list[i].pro -= capacity;

            return;
        }
    }
}

long long count_time(vector<customer> side, int max_cap)
{
    long long timer = 0;
    int times;

    int a, b;
    while (side.size() > 0)
    {
        times = 1;

        a = side.back().pro / max_cap;
        b = side.back().pro % max_cap;

        if (a > 0)
        {
            if (b == 0)
            {
                side.back().pro = 0;
                times = a;
            }
            else{
                times = a + 1;
                side.back().pro = b;
            }
        }

        timer += ((long long)side.back().x) * 2 * times;
        send_product(side, max_cap);
    }
    return abs(timer);
}

void solve()
{
    string line;
    getline(cin, line);

    int max_cap, no_of_custom;

    istringstream ss(line);

    ss >> line;
    no_of_custom = stoi(line);
    ss >> line;
    max_cap = stoi(line);

    vector<customer> negative_side;
    vector<customer> positive_side;

    int x, pro;
    customer cus;

    string word;
    for (int i = 0; i < no_of_custom; i++)
    {
        getline(cin, word);
        istringstream ss(word);

        ss >> word;
        x = stoi(word);
        ss >> word;
        pro = stoi(word);

        cus = create_customer(x, pro);
        if (x > 0)
            positive_side.push_back(cus);
        else
        {
            negative_side.push_back(cus);
        }
    }

    sort(negative_side.begin(), negative_side.end(), descend);
    sort(positive_side.begin(), positive_side.end(), increase);

    cout << count_time(positive_side, max_cap) + count_time(negative_side, max_cap) << endl;
}

int main()
{
    solve();
}
