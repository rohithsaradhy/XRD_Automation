Imports System.IO
Imports System

Imports System.Text

Public Class Form1
    Dim Num As Boolean = False
    Delegate Sub SetTextCallback(ByVal [text] As String)
    Private Sub Form1_Leave(sender As Object, e As EventArgs) Handles Me.Leave
        SerialPort1.Close()

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        SerialPort1.Open()

    End Sub

    Private Sub CheckText()
        If IsNumeric(TextBox1.Text) And IsNumeric(TextBox3.Text) And IsNumeric(TextBox2.Text) Then
            Num = True
        Else
            Num = False
        End If
    End Sub




    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        SerialPort1.Write("CLR;" & vbCrLf & "Q;" & vbCrLf)
    End Sub

    Private Sub SerialPort1_DataReceived(sender As System.Object, e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        ReceivedText(SerialPort1.ReadExisting())
    End Sub

    Private Sub ReceivedText(ByVal [text] As String) 'input from ReadExisting
        If Me.RichTextBox1.InvokeRequired Then
            Dim x As New SetTextCallback(AddressOf ReceivedText)
            Me.Invoke(x, New Object() {(text)})
        Else
            Me.RichTextBox1.Text &= [text] 'append text
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        CheckText()
        If Num = True Then
            Dim firNum As Decimal = TextBox1.Text
            Dim secNum As Decimal = TextBox2.Text

            Dim RunTimes As Double = secNum - firNum
            Dim NoRun As Integer = RunTimes / 0.002
            RichTextBox1.Text += NoRun.ToString & vbCrLf & RunTimes.ToString & vbCrLf


            SerialPort1.Write("CLR;" & vbCrLf & "CCNT;" & vbCrLf & "1:A" + TextBox1.Text + "S500L10000B10;" & vbCrLf & "NL;" & vbCrLf & _
                              "2:A" + TextBox1.Text + "S500L10000B10;" & vbCrLf & "NL;" & vbCrLf & "GSB10*" + NoRun.ToString + ";" & vbCrLf & "NL;" _
                              & vbCrLf & "END;" & vbCrLf & "LIN10;" & vbCrLf & "1:+.002S1500;" & vbCrLf _
                              & "NL;" & vbCrLf & "2:+.004S1500;" & vbCrLf & "NL;" & vbCrLf & "CNT" + TextBox3.Text + ";" & "NL;" & vbCrLf _
                              & vbCrLf & "DELAY" + TextBox4.Text + ";" & _
                              vbCrLf & "NL;" & vbCrLf & "RET;" & vbCrLf & "NL;" & vbCrLf _
                              & "START:;" & vbCrLf)


            Num = False

        Else

        End If
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        SerialPort1.Write("CLR;" & vbCrLf & "?CNT;" & vbCrLf)
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        SerialPort1.Write("?P;" & vbCrLf)
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        DETECTOR_ANGLE.Show()

    End Sub



    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        SaveForm.Show()


    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        MonoCr.Show()

    End Sub
End Class
