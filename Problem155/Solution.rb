class MinStack
  # Initialize your data structure here
  def initialize

    @index = -1

    @max_index = -1

    @datas = Array.new

    @min_stack = Array.new

    @min_stack_index = -1

    @min_stack_max_index = -1

  end

  # @param {Integer} x
  # @return {Void} nothing
  def push(x)

    if @index < @max_index

      @index += 1

      @datas[@index] = x

    else

      @datas << x

      @index += 1

      @max_index = @index

    end

    if @min_stack_max_index < 0

      @min_stack << x

      @min_stack_index += 1

      @min_stack_max_index = @min_stack_index

    elsif @min_stack_index < 0 or @min_stack[@min_stack_index] >= x

      if @min_stack_index < @min_stack_max_index

        @min_stack_index += 1

        @min_stack[@min_stack_index] = x

      else

        @min_stack << x

        @min_stack_index += 1

        @min_stack_max_index = @min_stack_index

      end

    end

  end

  # @return {Void} nothing
  def pop

    if @index > -1

      if @datas[@index] == @min_stack[@min_stack_index]
        @min_stack_index -= 1

      end

      @index -= 1
    end

  end

  # @return {Integer}
  def top

    if @index > -1
      return @datas[@index]
    end

    0

  end

  # @return {Integer}
  def get_min

    if @index < 0
      return 0
    end

    @min_stack[@min_stack_index]

  end
end

min_stack = MinStack.new

# min_stack.push(-1)

# puts min_stack.top

# puts min_stack.get_min

min_stack.push 2147483646

min_stack.push 2147483646

min_stack.push 2147483647

min_stack.pop
min_stack.pop
min_stack.pop

min_stack.push 2147483647

puts min_stack.get_min