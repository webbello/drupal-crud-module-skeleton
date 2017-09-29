<h3>ONGOING/UPCOMING COURSES</h3>
<?php print $form; ?>
<hr>

<table class="sticky-enabled table-select-processed tableheader-processed sticky-table">
  <thead>
    <tr>
      <th># </th>
      <th>Announcement</th>
      <th>Action</th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($result as $key => $value) { ?>
        <tr>
          <td><img src="<?php echo base_path(); ?>upload/courses/<?php echo $value->thumbnail; ?>"> </td>
          <td><a href="<?php echo $value->url; ?>"><?php echo $value->title; ?></a></td>
          <td><a class="btn btn-primary" href="courses/?id=<?php echo $value->id; ?>" role="button">Edit</a></td>
        </tr>
    <?php } ?>
    
  </tbody>
</table>