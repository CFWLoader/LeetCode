# @param {Integer} n
# @return {Integer}
def bulb_switch(n)

  if n < 1
    return 0
  end

  count = 0

  1.upto(n) {|val|
    if fully_divide_count(val) % 2 == 1
      count += 1
    end
  }

  count

end

def fully_divide_count(num)

  count = 0

  1.upto(num) { |val|
    if num % val == 0
      count += 1
    end
  }

  count
end

puts bulb_switch 8