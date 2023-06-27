#2023/6/26 ~P.184
#2023/6/27 ~P.184
    - gdbデバッグ
        - osbbok/devenv/run_image.shを編集
            -   qemu-system-x86_64 \
                -m 1G \
                -drive if=pflash,format=raw,readonly,file=$DEVENV_DIR/OVMF_CODE.fd \
                -drive if=pflash,format=raw,file=$DEVENV_DIR/OVMF_VARS.fd \
                -drive if=ide,index=0,media=disk,format=raw,file=$DISK_IMG \
                -device nec-usb-xhci,id=xhci \
                -device usb-mouse -device usb-kbd \
                -monitor stdio \
                -s \
                -S \
                $QEMU_OPTS
        - 新規ターミナル起動
        `gdb`
        `file mikanos/kernel/kernel.elf`
        `target remote :1234`
        b: ブレークポイント張る (b mikanos/kernel/main.cpp:268) elfにcppソース内容も含まれているためできる操作
        c: 続ける
        p: ポインタのさす内容（変数名等）の中身を見る
        参考：https://tomiylab.com/2021/09/gdb-mikanos/
    - objdump -S -d mikanos/kernel/kernel.elf > kernel.lst