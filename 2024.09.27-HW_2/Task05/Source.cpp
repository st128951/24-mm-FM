#include<iostream>

int main(int argc, char* argv[])
{
	int l1 = 0;
	int w1 = 0;
	int h1 = 0;
	int l2 = 0;
	int w2 = 0;
	int h2 = 0;
	int lc = 0;
	int wc = 0;
	int hc = 0;

	scanf_s("%d", &l1);
	scanf_s("%d", &w1);
	scanf_s("%d", &h1);
	scanf_s("%d", &l2);
	scanf_s("%d", &w2);
	scanf_s("%d", &h2);
	scanf_s("%d", &lc);
	scanf_s("%d", &wc);
	scanf_s("%d", &hc);

	bool hf = (h1 > h2 ? h1 : h2) <= hc;
	bool hllw = (l1 > w2 ? l1 : w2) <= lc;
	bool hwlw = (l2 > w1 ? l2 : w1) <= wc;
	bool hlwl = (l1 > w2 ? l1 : w2) <= wc;
	bool hwwl = (l2 > w1 ? l2 : w1) <= lc;
	bool hlf = (l1 > l2 ? l1 : l2) <= wc;
	bool hwf = (w1 > w2 ? w1 : w2) <= lc;
	bool lf = (l1 > l2 ? l1 : l2) <= lc;
	bool wf = (w1 > w2 ? w1 : w2) <= wc;
	bool lls = (l1 + l2) <= lc;
	bool lws = (w1 + w2) <= lc;
	bool lwswf = (l1 > l2 ? l1 : l2) <= wc;
	bool llw = (l1 + w2) <= lc;
	bool llwwf = (w1 > l2 ? w1 : l2) <= wc;
	bool lwl = (l2 + w1) <= lc;
	bool lwlwf = (l1 > w2 ? l1 : w2) <= wc;
	bool wls = (l1 + l2) <= wc;
	bool wlslf = (w1 > w2 ? w1 : w2) <= lc;
	bool wws = (w1 + w2) <= wc;
	bool wlw = (l1 + w2) <= wc;
	bool wlwlf = (w1 > l2 ? w1 : l2) <= lc;
	bool wwl = (l2 + w1) <= wc;
	bool wwllf = (l1 > w2 ? l1 : w2) <= lc;

	if (((h1 + h2) <= hc && ((lf && wf) || (hllw && hwlw) || (hlwl && hwwl) || (hlf && hwf))) || (hf && ((lls && wf) || (lws && lwswf) || (llw && llwwf) || (lwl && lwlwf)) || (hf && ((wls && wlslf) || (wws && lf) || (wlw && wlwlf) || (wwl && wwllf)))))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	return EXIT_SUCCESS;
}
