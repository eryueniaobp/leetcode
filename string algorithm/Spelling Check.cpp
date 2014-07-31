/* 给一个很大的词典，设计一个spelling check 如果拼错，给出最合适的近似词 */ 
// 核心结构：  k-gram 
/**
 * prerequisite : k-gram inverted index .
 * Step 1.找出query的所有 k-gram 对应的 word 集合  word_set_1 
 * Step 2. 利用Jaccard Distance（集合距离) < max_dis 缩小word_set_1 => word_set_2 
 * Step 3. 针对word_set_2 ，每个都进行 edit distance 的计算即可   
 */

/**
 * 精细化的因素： 
 *  单纯利用edit distance找出的最优集合为 word_set_3 ，如何再选优? 
 *     1. 利用 词 在所有query中出现的频率或在所有文档中出现的频率 。。
 *     2. 利用 键盘布局 来设定 字母拼错的概率，例如 W，E键盘上离得近，这两个拼错的概率就高  
 */ 

/** 
 * context-sensitive spelling check技术 
 * 考虑上下文  
 *
 * 一般演化为  考虑双词的k-gram即可 。。 双词的词表已经非常大了 .
 */ 

