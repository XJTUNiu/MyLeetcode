class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
	string codes[] = { ".-","-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	set<string> s1 = set<string>();
	vector<string>::iterator it;
	for (it=words.begin(); it!=words.end(); it++) {
		string res;
		for (int i = 0; i < (*it).length(); i++) {
			res = res.append(codes[(*it)[i] - 'a']);
		}
		s1.insert(res);
	}
	return s1.size();
	}
};
