#!/usr/bin/env python
# Created by Bruce yuan on 18-1-25.
"""
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
"""
import re


class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        result = {}
        for item in paths:
            result = self.__extract_content(item, result)

        return [x for x in result.values() if len(x) > 1]

    def __extract_content(self, string, result):
        """
        把括号里面的内容匹配出来
        :param string: 
        :param result: 一个字典，用来存储匹配结果
        :return: 
        """
        # group(1) 就是文件名，group(2)就是文件内容
        file_content = re.compile(r'(.*)\((.*)\)')
        dir_and_files = string.split(' ')
        directory, files = dir_and_files[0], dir_and_files[1:]
        # print(directory)
        for item in files:
            matched = file_content.match(item)
            if matched is not None:
                content = matched.group(2)
                file_name = matched.group(1)
                if result.get(content, None):
                    result.get(content).append(directory + '/' + file_name)
                else:
                    result[content] = [directory + '/' + file_name]
        # print(result)
        return result


def main():
    solution = Solution()
    result = solution.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"])
    result2 = solution.findDuplicate(["root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"])
    print(result2)
    print(result)


if __name__ == '__main__':
    main()
