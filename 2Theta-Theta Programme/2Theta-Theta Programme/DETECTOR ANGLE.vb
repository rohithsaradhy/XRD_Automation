Public Class DETECTOR_ANGLE
    Dim Num As Boolean = False
    Delegate Sub SetTextCallback(ByVal [text] As String)
    Dim Sign As Char = "+"



    Private Sub CheckText()
        If IsNumeric(TextBox1.Text) And IsNumeric(TextBox3.Text) And IsNumeric(TextBox2.Text) Then
            Num = True
        Else
            Num = False
        End If
    End Sub




    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form1.SerialPort1.Write("CLR;" & vbCrLf & "Q;" & vbCrLf)
    End Sub


    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        CheckText()
        If Num = True Then
            Dim firNum As Decimal = TextBox1.Text
            Dim secNum As Decimal = TextBox2.Text

            Dim RunTimes As Double = secNum - firNum
            Dim NoRun As Integer = RunTimes / 0.004

            If NoRun < 0 Then
                NoRun *= -1

            End If

            Form1.SerialPort1.Write("CLR;" & vbCrLf & "CA2;" & vbCrLf & "CCNT;" & vbCrLf & "1:A" + TextBox1.Text + "S500L10000B10;" & vbCrLf & "NL;" & vbCrLf & _
                              "2:A" + TextBox1.Text + "S500L10000B10;" & vbCrLf & "NL;" & vbCrLf & "GSB10*" + NoRun.ToString + ";" & vbCrLf & "NL;" _
                              & vbCrLf & "END;" & vbCrLf & "LIN10;" & vbCrLf & "2:" + Sign + ".004S1500;" & vbCrLf & "NL;" & vbCrLf & "CNT" + TextBox3.Text + ";" & vbCrLf & "NL;" _
                              & vbCrLf & "DELAY" + TextBox4.Text + ";" & _
                              vbCrLf & "NL;" & vbCrLf & "RET;" & vbCrLf & "NL;" & vbCrLf _
                              & "START:;" & vbCrLf)


            Num = False

        Else

        End If
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Form1.SerialPort1.Write("CLR;" & vbCrLf & "?CNT;" & vbCrLf)
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        If Sign = "+" Then
            Sign = "-"
            Button4.Text = "Currently Negative"
        Else
            Sign = "+"
            Button4.Text = "Currently Positive"
        End If
    End Sub
End Class