<?php

/**
 * @file
 * User page callbacks for the Forum module.
 */

function uploadFile($params = [])
{
    
    $allowed = array("jpg" => "image/jpg", "jpeg" => "image/jpeg", "gif" => "image/gif", "png" => "image/png");

    $filename = $params['cssteap_news_thumbnail']['name'];

    $filetype = $params['cssteap_news_thumbnail']['type'];

    $filesize = $params['cssteap_news_thumbnail']['size'];


    // Verify file extension

    $ext = pathinfo($filename, PATHINFO_EXTENSION);
    //var_dump($ext);die;

    if(!array_key_exists($ext, $allowed)) die("Error: Please select a valid file format.");



    // Verify file size - 5MB maximum

    $maxsize = 5 * 1024 * 1024;

    if($filesize > $maxsize) die("Error: File size is larger than the allowed limit.");



    // Verify MYME type of the file

    if(in_array($filetype, $allowed)){

        // Check whether file exists before uploading it

        if(file_exists("upload/announcement/" . $_FILES["cssteap_news_thumbnail"]["name"])){

            echo $_FILES["cssteap_news_thumbnail"]["name"] . " is already exists.";

        } else{

            move_uploaded_file($_FILES["cssteap_news_thumbnail"]["tmp_name"], "upload/announcement/" . $_FILES["cssteap_news_thumbnail"]["name"]);

            echo "Your file was uploaded successfully.";

        } 

    } else{

        echo "Error: There was a problem uploading your file. Please try again."; 

    }
}

function cssteap_updates_page_ajax($cssteap_updates_term = NULL) {
    $params = [
      'cssteap_news' => $_POST['cssteap_news'], 
      'cssteap_news_url' => $_POST['cssteap_news_url'],
      'cssteap_news_thumbnail' => $_FILES['cssteap_news_thumbnail']
    ];

  // Check if the form was submitted
  if($_SERVER["REQUEST_METHOD"] == "POST"){
    // Check if file was uploaded without errors
    //var_dump($_FILES["cssteap_news_thumbnail"]);die;
      if(isset($_FILES["cssteap_news_thumbnail"]) && $_FILES["cssteap_news_thumbnail"]["error"] == 0){
        uploadFile($params);
      }else{
        echo "Error: " . $_FILES["cssteap_news_thumbnail"]["error"];
      }
    
  }
  if (isset($_REQUEST['login'])) {
    echo('hi');die;
  }

  if (isset($_POST['cssteap_news_id']) && !empty($_POST['cssteap_news_id'])) {
    updateAnnouncement($_POST['cssteap_news_id']);
  } else if (!empty($_POST['cssteap_news'])){
    createAnnouncement($params);
  } else {
    form_set_error('error_message', t('Please fill all the required field'));
  }

  drupal_goto('admin/cssteap_updates');

}