<?php

/**
 * @file
 * User page callbacks for the Forum module.
 */

/**
 * Page callback: Prints a forum listing.
 *
 * @param $cssteap_updates_term
 *   A tree of all forums for a given taxonomy term ID. Defaults to NULL. See
 *   the return object of cssteap_forum_cssteap_forum_load() for a complete definition.
 *
 * @return
 *   A string containing HTML representing the themed forum listing.
 *
 * @see cssteap_updates_menu()
 */
require_once('helper.inc');

function cssteap_updates_page() {

  $output = theme('cssteap', array('links' => ''));

  return $output;

}
function cssteap_updates_page_announcement($cssteap_updates_term = NULL) {

  $result = getAnnouncement();
  //var_dump($result);die;
  $getForm = drupal_get_form('announcement_form');
  $form = drupal_render($getForm);

  //var_dump($form);
  $output = theme('announcement', array('form' => $form, 'result' => $result, 'editData' => []));

  return $output;

}

function cssteap_updates_page_courses($cssteap_updates_term = NULL) {

  $result = getCoursesAdmin();
  $getForm = drupal_get_form('cources_form');
  $form = drupal_render($getForm);

  $output = theme('courses', array('form' => $form, 'result' => $result));

  return $output;

}

function getAnnouncementById($id){
  
  $query = db_select('announcement', 'a')
    ->fields('a')
    ->condition('id', $id) ;

  $result = $query->execute()->fetch();
  return $result;
}
function getCourseById($id){
  
  $query = db_select('news_courses', 'a')
    ->fields('a')
    ->condition('id', $id) ;

  $result = $query->execute()->fetch();
  return $result;
}

function createAnnouncement($params =[])
{

  $query = db_insert('announcement') // Table name no longer needs {}
      ->fields(array(
        'title' => $params['news_title'],
        'url' => $params['news_link'],
        'thumbnail' => $params['news_image'],
        // 'created_at' => REQUEST_TIME,
        // 'updated_at' => REQUEST_TIME,
      ))
      ->execute();
}
function updateAnnouncement($params = [])
{
  //var_dump($params);die;
  $query = db_update('announcement') // Table name no longer needs {}
      ->fields(array(
        'title' => $params['news_title'],
        'url' => $params['news_link'],
        'thumbnail' => $params['news_image'],
        // 'created_at' => REQUEST_TIME,
        // 'updated_at' => REQUEST_TIME,
      ))
      ->condition('id', $params['id'])
      ->execute();
}

function createCourses($params = [])
{
  //var_dump($params);die;
  $query = db_insert('news_courses') // Table name no longer needs {}
      ->fields(array(
        'title' => $params['news_title'],
        'url' => $params['news_link'],
        'thumbnail' => $params['news_image'],
        'status' => $params['course_type'],
        'expire_on' => $params['expire_on'],
        // 'created_at' => REQUEST_TIME,
        // 'updated_at' => REQUEST_TIME,
      ))
      ->execute();
}
function updateCourses($params = [])
{
  //var_dump($params);die;
  $query = db_update('news_courses') // Table name no longer needs {}
      ->fields(array(
        'title' => $params['news_title'],
        'url' => $params['news_link'],
        'thumbnail' => $params['news_image'],
        'status' => $params['course_type'],
        'expire_on' => $params['expire_on'],
        // 'created_at' => REQUEST_TIME,
        // 'updated_at' => REQUEST_TIME,
      ))
      ->condition('id', $params['id'])
      ->execute();
}

