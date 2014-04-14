import sys

class Solution :
	def reverseWords(self, s) :
		s = self.reverseWord(s)
		ss = s.split(" ")
		res = []
		for item in ss :
			res.append(self.reverseWord(item))
		return " ".join(res)
	
	def reverseWord(self, s) :
		s = [i for i in s]
		l = len(s)
		for i in xrange(l/2) :
			s[i], s[l-i-1] = s[l-i-1], s[i]
		return "".join(s)

if __name__ == "__main__" :
	w = "the sky is blue"
	w = "the       ske   tt dfaf a     "
	s = Solution()
	print s.reverseWords(w)
