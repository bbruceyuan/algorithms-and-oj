#!/usr/bin/env python
# Created by Bruce yuan on 18-2-12.


import numpy


class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.element = []
        self.min = numpy.Inf
        self.count = 0

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.element.append(x)
        self.count += 1
        if x < self.min:
            self.min = x

    def pop(self):
        """
        :rtype: void
        """
        x = self.element.pop()
        self.count -= 1
        if x == self.min:
            if self.count == 0:
                self.min = numpy.Inf
            else:
                self.min = min(self.element)

    def top(self):
        """
        :rtype: int
        """
        return self.element[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
