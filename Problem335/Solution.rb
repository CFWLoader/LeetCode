# @param {Integer[]} x
# @return {Boolean}
def is_self_crossing(x)

  if x == nil
    return false
  end

  crossX = false, crossY = false

  positionX = 0, positionY = 0

  newX = 0, newY = 0

  counter = 0

  x.each do |val|
    case counter % 4
      when 0
        newY = positionY += val
        if positionY <= 0 and newY
          crossY
        end
      when 1
      when 2
      when 3
    end

    if crossX and crossY
      return true
    end

    ++counter
  end

  false
end

puts is_self_crossing [1, 1, 1, 1]
