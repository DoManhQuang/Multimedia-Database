/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ungdungnenlzw;

import java.io.EOFException;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 *
 * @author trongson
 */
public class NenAnhDungLZW extends javax.swing.JFrame {

    /**
     * Creates new form NenAnhDungLZW
     */
    static public String[] arrayOfChar;
    public static HashMap<String, Integer> dictionary = new HashMap<>();
    public static int dictSize = 256;
    public static String P = "", filename = "", BP = "";
    public static byte inputByte;
    public static byte[] buffer = new byte[3];
    public static boolean isLeft = true;

    public NenAnhDungLZW() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jFileChooser1 = new javax.swing.JFileChooser();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Thuật toán LZW - nhóm 2");

        jButton1.setText("Chọn ảnh");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Nén ảnh");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("Giải nén ảnh");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jTextArea1.setColumns(20);
        jTextArea1.setFont(new java.awt.Font("Monospaced", 0, 16)); // NOI18N
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(152, 152, 152)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(154, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(76, 76, 76)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton3, javax.swing.GroupLayout.DEFAULT_SIZE, 47, Short.MAX_VALUE)
                    .addComponent(jButton2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(29, 29, 29)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(130, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        JFileChooser chooser = new JFileChooser("D:\\");
        int i = chooser.showOpenDialog(this);
        if (i == JFileChooser.APPROVE_OPTION) {
            File f = chooser.getSelectedFile();
            filename = chooser.getCurrentDirectory().toString() + chooser.getSelectedFile().getName();
            System.out.println("File name: " + filename);
        } else {
            JOptionPane.showMessageDialog(rootPane, "Bạn chưa chọn file nào cả");
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        try {
            // TODO add your handling code here:
            compress();
        } catch (IOException ex) {
            Logger.getLogger(NenAnhDungLZW.class.getName()).log(Level.SEVERE, null, ex);
        }
        String[] getFileNameWOExtn = filename.split("\\.");
        jTextArea1.setText("Đã nén thành công!\n kiểm tra file:\n" + getFileNameWOExtn[0].concat(".lzw"));
        System.out.println("Compression complete!Check file " + getFileNameWOExtn[0].concat(".lzw"));
        filename = getFileNameWOExtn[0].concat(".lzw");
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        try {
            // TODO add your handling code here:
            decompress();
        } catch (IOException ex) {
            Logger.getLogger(NenAnhDungLZW.class.getName()).log(Level.SEVERE, null, ex);
        }
        String[] getFileNameWOExtn = filename.split("\\.");
        jTextArea1.setText("Đã giải nén thành công!\n kiểm tra file:\n" + getFileNameWOExtn[0].concat(".bmp"));
        System.out.println("Compression complete!Check file " + getFileNameWOExtn[0].concat(".bmp") + "!");
    }//GEN-LAST:event_jButton3ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Windows".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(NenAnhDungLZW.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NenAnhDungLZW.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NenAnhDungLZW.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NenAnhDungLZW.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new NenAnhDungLZW().setVisible(true);
        });
    }

    public static void compress() throws IOException {

        int i, byteToInt;
        char C;

        // Character dictionary 
        for (i = 0; i < 256; i++) {
            dictionary.put(Character.toString((char) i), i);
        }

        // Read input file and output file
        RandomAccessFile inputFile = new RandomAccessFile(filename, "r");
        String[] getFileNameWOExtn = filename.split("\\.");
        RandomAccessFile outputFile = new RandomAccessFile(getFileNameWOExtn[0].concat(".lzw"), "rw");

        try {

            // Read first byte to initialize P
            inputByte = inputFile.readByte();
            byteToInt = new Byte(inputByte).intValue();

            if (byteToInt < 0) {
                byteToInt += 256;
            }
            C = (char) byteToInt;
            P = "" + C;

            while (true) {
                inputByte = inputFile.readByte();
                byteToInt = new Byte(inputByte).intValue();

                if (byteToInt < 0) {
                    byteToInt += 256;
                }
                C = (char) byteToInt;

                // if P+C is present in dictionary
                if (dictionary.containsKey(P + C)) {
                    P = P + C;
                } /* 
                 if P+C is not in dictionary, we obtain the longest string in the dictionary 
                 so far which is stored in P. The value of this string is converted in binary. 
                 This binary number is then padded to make it 12 bits long (for standardization
                 and avoing overflow or underflow caused using 8 bits). This is then converted 
                 into bytes and stored.
                   
                 We write in the file every 2 characters.
                 */ else {
                    BP = convertTo12Bit(dictionary.get(P));
                    if (isLeft) {
                        buffer[0] = (byte) Integer.parseInt(BP.substring(0, 8), 2);
                        buffer[1] = (byte) Integer.parseInt(BP.substring(8, 12) + "0000", 2);
                    } else {
                        buffer[1] += (byte) Integer.parseInt(BP.substring(0, 4), 2);
                        buffer[2] = (byte) Integer.parseInt(BP.substring(4, 12), 2);
                        for (i = 0; i < buffer.length; i++) {
                            outputFile.writeByte(buffer[i]);
                            buffer[i] = 0;
                        }
                    }
                    isLeft = !isLeft;
                    if (dictSize < 4096) {
                        dictionary.put(P + C, dictSize++);
                    }

                    P = "" + C;
                }
            }

        } /*  
         If isLeft is true, we store the current data in BP to buffer[0] and buffer[1]. Then these 
         buffers are written in the output file.
         If isLeft is false, we already have data in the first and half of seccond byte of the 
         buffer. Hence, we store the current value of BP and write all the 3 bytes to the outputFile. 
            
         When the file input is complete, the while loop will still execute due to the condition.
         This ensures that the file is read completely but it might throw an error if there is 
         no input left in the inputFile. So, when an error is thrown, we store the remaining contents
         of the buffer.
         */ catch (IOException ie) {
            BP = convertTo12Bit(dictionary.get(P));
            if (isLeft) {
                buffer[0] = (byte) Integer.parseInt(BP.substring(0, 8), 2);
                buffer[1] = (byte) Integer.parseInt(BP.substring(8, 12) + "0000", 2);
                outputFile.writeByte(buffer[0]);
                outputFile.writeByte(buffer[1]);
            } else {
                buffer[1] += (byte) Integer.parseInt(BP.substring(0, 4), 2);
                buffer[2] = (byte) Integer.parseInt(BP.substring(4, 12), 2);
                for (i = 0; i < buffer.length; i++) {
                    outputFile.writeByte(buffer[i]);
                    buffer[i] = 0;
                }
            }
            inputFile.close();
            outputFile.close();
        }

    }

    public static String convertTo12Bit(int i) {
        String to12Bit = Integer.toBinaryString(i);
        while (to12Bit.length() < 12) {
            to12Bit = "0" + to12Bit;
        }
        return to12Bit;
    }

    public static void decompress() throws IOException {
        isLeft = true;
        // String filename = "", extension = "";
        int currentword, previousword;
        // byte[] buffer = new byte[3];
        // boolean isLeft = true;
        arrayOfChar = new String[4096];
        int i;

        for (i = 0; i < 256; i++) {
            arrayOfChar[i] = Character.toString(
                    (char) i
            );
        }

        // Read input file and output file
        RandomAccessFile inputFile = new RandomAccessFile(filename, "r");
        String[] getFileNameWOExtn = filename.split("\\.");
        RandomAccessFile outputFile = new RandomAccessFile(getFileNameWOExtn[0].concat(".bmp"), "rw");

        try {
            buffer[0] = inputFile.readByte();
            buffer[1] = inputFile.readByte();
            previousword = getIntValue(buffer[0], buffer[1], isLeft);
            isLeft = !isLeft;
            outputFile.writeBytes(arrayOfChar[previousword]);

            // Reads three bytes and generates corresponding characters
            while (true) {

                if (isLeft) {
                    buffer[0] = inputFile.readByte();
                    buffer[1] = inputFile.readByte();
                    currentword = getIntValue(buffer[0], buffer[1], isLeft);
                } else {
                    buffer[2] = inputFile.readByte();
                    currentword = getIntValue(buffer[1], buffer[2], isLeft);
                }
                isLeft = !isLeft;

                /*
                 currentword not in dictionary, we just add the previousword in the entry.
                 */
                if (currentword >= dictSize) {
                    if (dictSize < 4096) {
                        arrayOfChar[dictSize] = arrayOfChar[previousword] + arrayOfChar[previousword].charAt(0);
                    }
                    dictSize++;
                    outputFile.writeBytes(arrayOfChar[previousword] + arrayOfChar[previousword].charAt(0));
                } /*
                 If word is present, we form a word with the previousword and the first character of the 
                 currentword and add it in a new entry
                 */ else {
                    if (dictSize < 4096) {
                        arrayOfChar[dictSize] = arrayOfChar[previousword] + arrayOfChar[currentword].charAt(0);
                    }
                    dictSize++;
                    outputFile.writeBytes(arrayOfChar[currentword]);
                }
                previousword = currentword;
            }
        } catch (EOFException e) {
            inputFile.close();
            outputFile.close();
        }
    }

    /*
     Converting 2 bytes to 12-bit code.
     Converting 12-bit code to integer value.
     */
    public static int getIntValue(byte b1, byte b2, boolean isLeft) {
        String t1 = Integer.toBinaryString(b1);
        String t2 = Integer.toBinaryString(b2);

        while (t1.length() < 8) {
            t1 = "0" + t1;
        }
        if (t1.length() == 32) {
            t1 = t1.substring(24, 32);
        }

        while (t2.length() < 8) {
            t2 = "0" + t2;
        }
        if (t2.length() == 32) {
            t2 = t2.substring(24, 32);
        }

        if (isLeft) {
            return Integer.parseInt(t1 + t2.substring(0, 4), 2);
        } else {
            return Integer.parseInt(t1.substring(4, 8) + t2, 2);
        }

    }


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JFileChooser jFileChooser1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
}