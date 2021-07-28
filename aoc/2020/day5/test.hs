f :: Char -> (Int, Int) -> String -> Int
f _ (minx, maxx) [] = minx
f minc (minx, maxx) (c:cs)
  | c == minc     = f' (minx, minx+dxhalf) cs
  | otherwise    = f' (maxx-dxhalf, maxx) cs
  where
    dxhalf = (maxx-minx) `div` 2
    f' = f minc

row :: String -> Int
row = f 'F' (0, 127)

col :: String -> Int
col = f 'L' (0, 7)
