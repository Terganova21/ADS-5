// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char oper) {
    if (oper == '+' || oper == '-')
        return 1;
    if (oper == '(')
        return 0;
    if (oper == '*' || oper == '/')
        return 0;
    return -1;
}

std::string infx2pstfx(std::string inf) {
	TStack <char, 100> st;
    std::string post;
    for (int k = 0; k < inf.size(); k++) {
        int pr = prior(inf[i]);
        if ((prior(inf[k]) == -1) && (inf[k] != ')')) {
            if (!post.empty() && prior(inf[k - 1]) != -1) {
                post.push_back(' ');
            }
            post.push_back(inf[k]);

        } else if ((prior(inf[k]) > prior(st.get()))
                   || (st.isEmpty()) || (inf[k] == '(')) {
            st.push(inf[k]);
        } else {
            if (inf[k] == ')') {
                while (st.get() != '(') {
                    post.push_back(' ');
                    post.push_back(st.get());
                    st.pop();
                }
                st.pop();
            } else {
                while (prior(st.get()) >= prior(inf[k])) {
                    post.push_back(' ');
                    post.push_back(st.get());
                    st.pop();
                }
                st.push(inf[k]);
            }
        }
    }
    while (!st.isEmpty()) {
        post.push_back(' ');
        if (st.get() != '(') {
            post.push_back(st.get());
        }
        st.pop();
    }
    return post;
}
int convert(char count) {
    int i = 0;
    if (count >= '0' && count <= '9') {
        for (char k = '0'; k <= '9'; k++, i++) {
            if (count == k)
                return i;
        }
    }
    return -1;
}

int eval(std::string pref) {
	int sum{ 0 };
	TStack<int> st;
	for (auto& el : pst)
	{
		if (un_num(el) == -1)
		{
			char k[2];
			k[0] = el;
			k[1] = '\0';
			int r = atoi(k);
			st.push(r);
		}
		else
		{
			int b = st.get();
			st.pop();
			int a = st.get();
			st.pop();
			st.push(counter(a, b, el));
		}
	}
	return st.get();
}
