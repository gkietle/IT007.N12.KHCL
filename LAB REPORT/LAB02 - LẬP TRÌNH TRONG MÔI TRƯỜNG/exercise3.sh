#! /bin/sh

while [ true ]; do
    # Cho phép chạy vòng lặp vô hạn
    echo -n "Nhap so: "
    # In ra "Nhap so: " và không xuống dòng
    read n
    # Nhập vào từ bàn phím cho biến n
    if [ $n -ge 10 ]; then
        # Kiểm tra giá trị của n có bé hơn 10 không
        break
        # Dừng lại vòng lặp
    else
        echo "So nhap vao < 10, xin hay nhap lai! "
        # In ra màn hình "So nhap vao < 10, xin hay nhap lai! "
    fi
done

sum=0
# Cho biến sum là kết quả cần tìm bằng 0

for i in $(seq 1 $n); do
    # Vòng lặp cho biến i chạy từ 1 đến n
    sum=$(($sum + $i))
    # Gán sum bằng sum + i
done
echo "Tong tu 1 den $n la: $sum"
# In ra màn hình "Tong tu 1 den $n la: $sum" với $n và $sum lần lượt là giá trị của n và sumSS