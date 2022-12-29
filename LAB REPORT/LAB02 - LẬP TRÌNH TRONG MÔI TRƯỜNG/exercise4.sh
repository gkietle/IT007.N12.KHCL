#! /bin/sh

echo -n "Nhap chuoi: "
read s
# Nhập vào từ bàn phím cho biến s

res=""
for file in *; do

    if [ -f $file ] && [ $(grep -l "$s" $file) ]; then
        res="$res $(grep -l "$s" $file)"
    fi
done

if [ "$res" = "" ]; then
    echo "$s khong xuat hien trong bat ky file nao trong thu muc hien hanh"
else
    echo "$s xuat hien trong:$res"
# In ra màn hình "Chuoi nhap vao xuat hien trong: $res" với $res là giá trị của res
fi