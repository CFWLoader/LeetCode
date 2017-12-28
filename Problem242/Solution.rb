# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)

  s_statistic = Array.new 26, 0

  t_statistic = Array.new 26, 0

  base_val = 'a'.ord

  s.each_char do |ch|

    s_statistic[ch.ord - base_val] += 1

  end

  t.each_char do |ch|

    t_statistic[ch.ord - base_val] += 1

  end

  index = 0;

  until index == 26

    if s_statistic[index] != t_statistic[index]
      return false
    end

    index += 1
  end

  true
end