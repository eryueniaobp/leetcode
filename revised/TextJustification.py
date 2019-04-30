class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        def foo(nums, words, maxwidth):
            i = 1 
            while sum(nums[:i]) + i -1 <= maxwidth and i <=len(nums) :
                  i += 1
            i = i -1 
            string = ''
            if i == len(words) or i == 1: #左对齐
                for word in words[:i]:
                    string += (word+' ')
                string += ' '*maxwidth
            else:
                avg_blanks = (maxwidth - sum(nums[:i])) // (i-1) 
                remainder = (maxwidth - sum(nums[:i])) % (i-1)  #多余空格处理
                for word in words[:i]:
                    string += (word + ' '* avg_blanks) 
                    if remainder: 
                        string += ' '
                        remainder -= 1 
            return i, string[:maxwidth]
                              
                  
        
        word_lens = [len(word) for word in words ]
        ans = []
        
        while words:
            i, an = foo(word_lens, words, maxWidth)
            ans.append(an)
            
            word_lens = word_lens[i:]
            words = words[i:]
        return ans 
        
