# @param {Integer} a
# @param {Integer} b
# @param {Integer} c
# @param {Integer} d
# @param {Integer} e
# @param {Integer} f
# @param {Integer} g
# @param {Integer} h
# @return {Integer}
def compute_area(a, b, c, d, e, f, g, h)

  total = (c - a) * (d - b) + (g - e) * (h - f)

  if a >= g or b >= h or c <= e or d <= f
    return total
  end

  top = d > h ? h : d

  bottom = b > f ? b : f

  left = a < e ? e : a

  right = c > g ? g : c

  overlap = (top - bottom) * (right - left)

  total - overlap
end