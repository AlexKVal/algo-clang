arr = [5, 13, 4, 16, 27, 3, 2, 35, 1]

print "Before:\t#{arr}\n"

arr[1..arr.length].each_with_index do |el, idx|
  while idx >= 0 && arr[idx] > el
    arr[idx + 1] = arr[idx]
    idx -= 1
  end
  arr[idx + 1] = el
end

# for nxt_idx in (1..(arr.length-1))
#   el = arr[nxt_idx]
#   idx = nxt_idx - 1
#   while idx >= 0 && arr[idx] > el
#     arr[idx + 1] = arr[idx]
#     idx -= 1
#   end
#   arr[idx + 1] = el
# end

print "After:\t#{arr}\n"
