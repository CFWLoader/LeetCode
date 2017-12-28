require 'thread'
require 'queue'

class Stack
  # Initialize your data structure here.
  def initialize

    @quque1 = Queue.new

    @queue2 = Queue.new

    @top_element = nil

  end

  # @param {Integer} x
  # @return {void}
  def push(x)

    if self.empty
      @queue1.push x

      return
    end

    if @queue1.empty?
      @queue1.push x

      until @queue2.empty?
        @quque1.push @queue2.pop
      end
    else
      @queue2.push x

      until @queue1.empty?
        @queue2.push @queue1.pop
      end
    end
  end

  # @return {void}
  def pop

    if @top_element.nil?
      if @queue1.empty?
        @queue2.pop
      else
        @queue1.pop
      end
    else
      @top_element = nil
    end

  end

  # @return {Integer}
  def top

    if @top_element.nil?
      @top_element = @quque1.empty? ? @queue2.pop : @queue1.pop
    end

    @top_element
  end

  # @return {Boolean}
  def empty
    @quque1.empty? and @queue2.empty?
  end
end

stack = Stack.new

stack.push 1

puts stack.top

puts stack.top