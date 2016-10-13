Public Class MonoCr

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Me.Close()

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        SerialPort2.Open()
        SerialPort2.Write(TextBox1.Text)
        SerialPort2.Close()
    End Sub
End Class