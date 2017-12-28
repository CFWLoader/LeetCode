# @param {String[]} words
# @return {Integer}
def max_product(words)

  if words.nil? or words.size < 1
    return 0
  end

  product = 0

  bound = words.size

  words_state = Array.new bound, 0

  baseline = 'a'.ord

  words.each_with_index { |val, idx|
    val.each_char { |ch|
      words_state[idx] |= 1 << (ch.ord - baseline)
    }
  }

  0.upto(bound - 2) { |i|

    (i + 1).upto(bound - 1) { |j|

      if words_state[i] & words_state[j] == 0
        current_product = words[i].size * words[j].size

        if current_product > product
          product = current_product
        end
      end

    }
  }

  product
end

=begin
def calculate_product(word1, word2)

  word1.each_char { |ch1|
    word2.each_char { |ch2|
      if ch1 == ch2
        return 0
      end
    }
  }

  word1.size * word2.size
end
=end


puts max_product %w(abcw baz foo bar xtfn abcdef)