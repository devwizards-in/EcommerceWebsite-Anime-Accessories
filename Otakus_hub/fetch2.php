<?php
$connect = mysqli_connect("localhost", "root", "947539", "dbgood");
$output = '';
if(isset($_POST["query"]))
{
	$search = mysqli_real_escape_string($connect, $_POST["query"]);
	$query = "
	SELECT * FROM tbgood 
	WHERE goodname LIKE '%".$search."%'
	OR categories LIKE '%".$search."%' 
	
	";
}
else
{
	$query = "
	SELECT * FROM tbgood ";
}
$result = mysqli_query($connect, $query);
if(mysqli_num_rows($result) > 0)
{
	$output .= '';
	while($row = mysqli_fetch_array($result))
	{
		$good_id= $row['good_id'];
		$output .= '
			<tr style="width:100%;background:white; border:1px solid black;">
				<td style="border-bottom:solid 1px black;padding:10px;"><a href="searchgood.php?good_id='.$good_id.'" style="text-decoration:none;font-weight:bold; color:black;padding:100px;">'.$row["goodname"].'</a></td>
				
			</tr>
		';
	}
	echo $output;
}
else
{
	echo 'Data Not Found';
}
?>